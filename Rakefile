require 'bundler'
Bundler::GemHelper.install_tasks

# use rake-compiler for building the extension
require 'rake/extensiontask'

Rake::ExtensionTask.new('ActiveMQ') do |ext|
  ext.source_pattern = "*.{c,cpp}"
end
