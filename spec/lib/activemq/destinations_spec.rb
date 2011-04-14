# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::Destination do
  describe "constants" do
    it "should has a defined DestinationType" do
      ActiveMQ::Destination.constants.should include("DestinationType")
    end

    it "should has a Class as DestinationType" do
      ActiveMQ::Destination::DestinationType.should be_instance_of(::Class)
    end

    it "should has some constants in the class DestinationType" do
      ActiveMQ::Destination::DestinationType.constants.should include_all(["TOPIC", "QUEUE", "TEMPORARY_TOPIC", "TEMPORARY_QUEUE"])
    end
  end

  describe "destination_type" do
    it "should create destination from type ActiveMQ::Destination::DestinationType::TOPIC" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_topic("TEST_SESSION").destination_type.should == ActiveMQ::Destination::DestinationType::TOPIC
    end

    it "should create destination from type ActiveMQ::Destination::DestinationType::QUEUE" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_queue("TEST_SESSION").destination_type.should == ActiveMQ::Destination::DestinationType::QUEUE
    end

    it "should create destination from type ActiveMQ::Destination::DestinationType::TEMPORARY_TOPIC" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_topic.destination_type.should == ActiveMQ::Destination::DestinationType::TEMPORARY_TOPIC
    end

    it "should create destination from type ActiveMQ::Destination::DestinationType::TEMPORARY_QUEUE" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_queue.destination_type.should == ActiveMQ::Destination::DestinationType::TEMPORARY_QUEUE
    end
  end

  describe "name" do
    it "should create topic destination with given name" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_topic("TEST_TOPIC").name.should == "TEST_TOPIC"
    end

    it "should create queue destination with given name" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_queue("TEST_QUEUE").name.should == "TEST_QUEUE"
    end

    it "should temporary topic respond to name" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_topic.should respond_to(:name)
    end

    it "should temporary queue respond to name" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_queue.should respond_to(:name)
    end
  end

end
