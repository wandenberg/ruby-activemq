# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "activemq/version"

Gem::Specification.new do |s|
  s.name        = "activemq"
  s.version     = ActiveMQ::VERSION
  s.platform    = Gem::Platform::RUBY
  s.authors     = ["Wandenberg Peixoto"]
  s.email       = ["wandenberg@gmail.com"]
  s.homepage    = ""
  s.summary     = %q{ActiveMQ client for Ruby}
  s.description = %q{ActiveMQ client for Ruby using openwire protocol through activemq-cpp client}

  s.rubyforge_project = "activemq"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]

  s.extensions = "ext/ActiveMQ/extconf.rb"

  s.add_dependency "rice", ">= 1.4.2"

  s.add_development_dependency "rake-compiler", ">= 0.7.7"
  s.add_development_dependency "rspec", ">= 2.3.0"

end
