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
		int HelloWorldDataSubscriber(int argc, char *argv[]);
}

int HelloWorldDataSubscriber(int argc, char *argv[])
{
	os_time delay_2ms = { 0, 2000000 };
	os_time delay_200ms = { 0, 200000000 };
	MessageSeq msgList;
	SampleInfoSeq infoSeq;

	DDSEntityManager mgr;

	// create domain participant
	mgr.createParticipant("HelloWorld example");

	//create type
	MessageTypeSupport_var mt = new MessageTypeSupport();
	mgr.registerType(mt.in());

	//create Topic
	char topic_name[] = "B2A1";
	mgr.createTopic(topic_name);

	//create Subscriber
	mgr.createSubscriber();

	// create DataReader
	mgr.createReader();

	DataReader_var dreader = mgr.getReader();
	MessageDataReader_var HelloWorldReader = MessageDataReader::_narrow(dreader.in());
	checkHandle(HelloWorldReader.in(), "MsgDataReader::_narrow");

	cout << "=== [Subscriber] Ready ..." << endl;

	bool closed = false;
	ReturnCode_t status = -1;
	int count = 0;
	while (!closed && count < 15000) // We dont want the example to run indefinitely
	{
		status = HelloWorldReader->take(msgList, infoSeq, LENGTH_UNLIMITED,
			ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
		checkStatus(status, "msgDataReader::take");
		for (DDS::ULong j = 0; j < msgList.length(); j++)
		{
			cout << "=== [Subscriber] message received :" << endl;
			cout << "    subjectId  : " << msgList[j].subjectId << endl;
			cout << "    Message : \"" << msgList[j].text << "\"" << endl;
			//closed = true;
		}
		status = HelloWorldReader->return_loan(msgList, infoSeq);
		checkStatus(status, "MsgDataReader::return_loan");
		os_nanoSleep(delay_200ms);
		++count;
	}

	os_nanoSleep(delay_2ms);

	//cleanup
	mgr.deleteReader();
	mgr.deleteSubscriber();
	mgr.deleteTopic();
	mgr.deleteParticipant();

	return 0;
}

int OSPL_MAIN(int argc, char *argv[])
{
	return HelloWorldDataSubscriber(argc, argv);
}
