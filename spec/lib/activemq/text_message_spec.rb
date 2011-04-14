# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::TextMessage do

  describe "text" do
    it "should create a text message without text" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_text_message.text.should be_empty
    end

    it "should create a text message with a message" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_text_message("message").text.should == "message"
    end

    it "should be possible to set text to a message" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      message = session.create_text_message
      message.text = "TEXT_MESSAGE"
      message.text.should == "TEXT_MESSAGE"
    end
  end

end
