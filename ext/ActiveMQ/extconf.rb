# Loads mkmf which is used to make makefiles for Ruby extensions
require 'rubygems'
require 'mkmf-rice'

# Add the arguments to the linker flags.
def append_ld_flags(flags)
  flags = [flags] unless flags.is_a?(Array)
  with_ldflags("#{$LDFLAGS} #{flags.join(' ')}") { true }
end

def crash(str)
  printf(" extconf failure: %s\n", str)
  exit 1
end

if RUBY_PLATFORM =~ /darwin/
  # In order to link the shared library into our bundle with GCC 4.x on OSX, we have to work around a bug:
  #   GCC redefines symbols - which the -fno-common prohibits.  In order to keep the -fno-common, we
  #   remove the flat_namespace (we now have two namespaces, which fixes the GCC clash).  Also, we now lookup
  #   symbols in both the namespaces (dynamic_lookup).

  $LDSHARED_CXX.gsub!('suppress', 'dynamic_lookup')
  $LDSHARED_CXX.gsub!('-flat_namespace', '')

  append_ld_flags '-all_load'
end


# Give it a name
extension_name = 'ActiveMQ'

# The destination
dir_config(extension_name)

dir_config('activemq-cpp', '/opt/activemq-cpp-3.2.5/include/activemq-cpp-3.2.5', '/opt/activemq-cpp-3.2.5/lib')

unless have_library('activemq-cpp')
  crash(<<EOL)
need activemq-cpp.

Install the activemq-cpp or try passing one of the following options
to extconf.rb:

  --with-activemq-cpp-dir=/path/to/activemq-cpp
  --with-activemq-cpp-lib=/path/to/activemq-cpp/lib
  --with-activemq-cpp-include=/path/to/activemq-cpp/include
EOL
end

# Do the work
create_makefile(extension_name)
