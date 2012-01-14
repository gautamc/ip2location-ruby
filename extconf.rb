# Copyright (C) 2005-2010 IP2Location.com
# All Rights Reserved
#
# This library is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either
# version 3 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; If not, see <http://www.gnu.org/licenses/>.

require 'mkmf'
dir_config('libIP2Location')
dir_config('includeIP2Location')
print "Creating Makefile... [", PLATFORM, "]\n" 
if have_library('IP2Location', 'IP2Location_open') then
    create_makefile("IP2Location")
else
    puts "No IP2Location library support available..."
end