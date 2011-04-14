# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::DeliveryMode do
  describe "constants" do
    it "should has a defined PERSISTENT" do
      ActiveMQ::DeliveryMode.constants.should include("PERSISTENT")
    end

    it "should PERSISTENT be equal to 0" do
      ActiveMQ::DeliveryMode::PERSISTENT.should == 0
    end

    it "should has a defined NON_PERSISTENT" do
      ActiveMQ::DeliveryMode.constants.should include("NON_PERSISTENT")
    end

    it "should NON_PERSISTENT be equal to 1" do
      ActiveMQ::DeliveryMode::NON_PERSISTENT.should == 1
    end
  end

  describe "new" do
    it "should be possible create an instance whithout any parameters" do
      delivery = ActiveMQ::DeliveryMode.new
      delivery.should be_instance_of(ActiveMQ::DeliveryMode)
    end
  end

end
