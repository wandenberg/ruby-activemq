require 'rspec/expectations'

RSpec::Matchers.define :include_all do |expected|
  match do |actual|
    expected.all? do |item|
      actual.include?(item)
    end
  end
end
