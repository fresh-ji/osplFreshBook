//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: MessengerDcps.h
//  Source: MessengerDcps.idl
//  Generated: Wed Feb 12 15:30:23 2020
//  OpenSplice 6.9.181018OSS
//  
//******************************************************************
#ifndef _MESSENGERDCPS_H_
#define _MESSENGERDCPS_H_

#include "sacpp_mapping.h"
#include "dds_dcps.h"
#include "Messenger.h"
#include "examples_export.h"


namespace Messenger
{

   class OS_EXAMPLE_API MessageTypeSupportInterface;

   typedef MessageTypeSupportInterface * MessageTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < MessageTypeSupportInterface> MessageTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < MessageTypeSupportInterface> MessageTypeSupportInterface_out;


   class OS_EXAMPLE_API MessageDataWriter;

   typedef MessageDataWriter * MessageDataWriter_ptr;
   typedef DDS_DCPSInterface_var < MessageDataWriter> MessageDataWriter_var;
   typedef DDS_DCPSInterface_out < MessageDataWriter> MessageDataWriter_out;


   class OS_EXAMPLE_API MessageDataReader;

   typedef MessageDataReader * MessageDataReader_ptr;
   typedef DDS_DCPSInterface_var < MessageDataReader> MessageDataReader_var;
   typedef DDS_DCPSInterface_out < MessageDataReader> MessageDataReader_out;


   class OS_EXAMPLE_API MessageDataReaderView;

   typedef MessageDataReaderView * MessageDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < MessageDataReaderView> MessageDataReaderView_var;
   typedef DDS_DCPSInterface_out < MessageDataReaderView> MessageDataReaderView_out;

   struct MessageSeq_uniq_ {};
   typedef DDS_DCPSUVLSeq < Message, struct MessageSeq_uniq_> MessageSeq;
   typedef DDS_DCPSSequence_var < MessageSeq> MessageSeq_var;
   typedef DDS_DCPSSequence_out < MessageSeq> MessageSeq_out;
   class OS_EXAMPLE_API MessageTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef MessageTypeSupportInterface_ptr _ptr_type;
      typedef MessageTypeSupportInterface_var _var_type;

      static MessageTypeSupportInterface_ptr _duplicate (MessageTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static MessageTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageTypeSupportInterface_ptr _this () { return this; }


   protected:
      MessageTypeSupportInterface () {};
      ~MessageTypeSupportInterface () {};
   private:
      MessageTypeSupportInterface (const MessageTypeSupportInterface &);
      MessageTypeSupportInterface & operator = (const MessageTypeSupportInterface &);
   };

   class OS_EXAMPLE_API MessageDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef MessageDataWriter_ptr _ptr_type;
      typedef MessageDataWriter_var _var_type;

      static MessageDataWriter_ptr _duplicate (MessageDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const Message& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const Message& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance_data) = 0;

   protected:
      MessageDataWriter () {};
      ~MessageDataWriter () {};
   private:
      MessageDataWriter (const MessageDataWriter &);
      MessageDataWriter & operator = (const MessageDataWriter &);
   };

   class OS_EXAMPLE_API MessageDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef MessageDataReader_ptr _ptr_type;
      typedef MessageDataReader_var _var_type;

      static MessageDataReader_ptr _duplicate (MessageDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataReader_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataReader_ptr _this () { return this; }

      virtual DDS::Long read (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance) = 0;

   protected:
      MessageDataReader () {};
      ~MessageDataReader () {};
   private:
      MessageDataReader (const MessageDataReader &);
      MessageDataReader & operator = (const MessageDataReader &);
   };

   class OS_EXAMPLE_API MessageDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef MessageDataReaderView_ptr _ptr_type;
      typedef MessageDataReaderView_var _var_type;

      static MessageDataReaderView_ptr _duplicate (MessageDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance) = 0;

   protected:
      MessageDataReaderView () {};
      ~MessageDataReaderView () {};
   private:
      MessageDataReaderView (const MessageDataReaderView &);
      MessageDataReaderView & operator = (const MessageDataReaderView &);
   };

}




#endif
