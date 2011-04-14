# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::ConnectionFactory do
  describe "constants" do
    it "should has a defined default_uri" do
      ActiveMQ::ConnectionFactory.constants.should include("DEFAULT_URI")
    end

    it "should has a string as default_uri" do
      ActiveMQ::ConnectionFactory::DEFAULT_URI.should be_instance_of(::String)
    end
  end

  describe "new" do
    it "should be possible create an instance whithout any parameters" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.should_not be_nil
    end

    it "should be created an instance with default values" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.broker_url.should == ActiveMQ::ConnectionFactory::DEFAULT_URI
      amqcf.username.should be_empty
      amqcf.password.should be_empty
      amqcf.client_id.should be_empty
    end

    it "should be possible pass only broker_url argument to create an instance with other attributes with default values" do
      amqcf = ActiveMQ::ConnectionFactory.new "url"
      amqcf.broker_url.should == "url"
      amqcf.username.should be_empty
      amqcf.password.should be_empty
      amqcf.client_id.should be_empty
    end

    it "should be possible pass broker_url and username arguments to create an instance with other attributes with default values" do
      amqcf = ActiveMQ::ConnectionFactory.new "url", "username"
      amqcf.broker_url.should == "url"
      amqcf.username.should == "username"
      amqcf.password.should be_empty
      amqcf.client_id.should be_empty
    end

    it "should be possible pass broker_url, username and password arguments to create an instance" do
      amqcf = ActiveMQ::ConnectionFactory.new "url", "username", "password"
      amqcf.broker_url.should == "url"
      amqcf.username.should == "username"
      amqcf.password.should == "password"
      amqcf.client_id.should be_empty
    end
  end

  describe "change attributes" do
    it "should be possible change broker_url attribute" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.broker_url = "url"
      amqcf.broker_url.should == "url"
    end

    it "should be possible change username attribute" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.username = "username"
      amqcf.username.should == "username"
    end

    it "should be possible change password attribute" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.password = "password"
      amqcf.password.should == "password"
    end

    it "should be possible change client_id attribute" do
      amqcf = ActiveMQ::ConnectionFactory.new
      amqcf.client_id = "client_id"
      amqcf.client_id.should == "client_id"
    end
  end

  describe "connection" do
    it "should create connection using instance attributes" do
      amqcf = ActiveMQ::ConnectionFactory.new BROKER_URL_TEST
      conn = amqcf.create_connection
      conn.client_id.should be_empty
      conn.close
    end

    it "should create connection using given username and password" do
      amqcf = ActiveMQ::ConnectionFactory.new BROKER_URL_TEST
      conn = amqcf.create_connection_for("username", "password")
      conn.client_id.should be_empty
      conn.close
    end

    it "should create connection using given username and password and instance client_id" do
      amqcf = ActiveMQ::ConnectionFactory.new BROKER_URL_TEST
      amqcf.client_id = "TEST"
      conn = amqcf.create_connection_for("username", "password")
      conn.client_id.should == "TEST"
      conn.close
    end

    it "should create connection using given username, password and client_id" do
      amqcf = ActiveMQ::ConnectionFactory.new BROKER_URL_TEST
      amqcf.client_id = "TEST"
      conn = amqcf.create_connection_for_client("username", "password", "client_id")
      conn.client_id.should == "client_id"
      conn.close
    end
  end
end
