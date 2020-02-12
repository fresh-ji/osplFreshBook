#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "ccpp_Messenger.h"
#include "vortex_os.h"

#include "example_main.h"

using namespace DDS;
using namespace Messenger;

/* entry point exported and demangled so symbol can be found in shared library */
extern "C"
{
	OS_API_EXPORT
		int HelloWorldDataPublisher(int argc, char *argv[]);
}

int HelloWorldDataPublisher(int argc, char *argv[])
{
	os_time delay_1s = { 1, 0 };
	DDSEntityManager mgr;

	// create domain participant
	mgr.createParticipant("HelloWorld example");

	//create type
	MessageTypeSupport_var mt = new MessageTypeSupport();
	mgr.registerType(mt.in());

	//create Topic
	char topic_name[] = "B2A1";
	mgr.createTopic(topic_name);

	//create Publisher
	mgr.createPublisher();

	// create DataWriter :
	// If autodispose_unregistered_instances is set to true (default value),
	// you will have to start the subscriber before the publisher
	bool autodispose_unregistered_instances = false;
	mgr.createWriter(autodispose_unregistered_instances);

	// Publish Events
	DataWriter_var dwriter = mgr.getWriter();
	MessageDataWriter_var HelloWorldWriter = MessageDataWriter::_narrow(dwriter.in());

	for (int i = 0; i < 100; i++)
	{
		Message msgInstance; /* Example on Stack */
		msgInstance.subjectId = i;
		msgInstance.text = DDS::string_dup("Hello World");
		cout << "=== [Publisher] writing a message containing :" << endl;
		cout << "    userID  : " << msgInstance.subjectId << endl;
		cout << "    Message : \"" << msgInstance.text << "\"" << endl;

		ReturnCode_t status = HelloWorldWriter->write(msgInstance, DDS::HANDLE_NIL);
		checkStatus(status, "MsgDataWriter::write");
		os_nanoSleep(delay_1s);
	}

	/* Remove the DataWriters */
	mgr.deleteWriter();

	/* Remove the Publisher. */
	mgr.deletePublisher();

	/* Remove the Topics. */
	mgr.deleteTopic();

	/* Remove Participant. */
	mgr.deleteParticipant();

	return 0;
}

int OSPL_MAIN(int argc, char *argv[])
{
	return HelloWorldDataPublisher(argc, argv);
}
