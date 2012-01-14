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

require 'IP2Location'

puts "------- IPv4 Sample --------"
IP2LocObj = IP2Location.new()
IP2LocObj.open("data/IP-COUNTRY-SAMPLE.BIN") # Unix like path separator. Must change to '\\' for Windows platform
rec = IP2LocObj.get_all("19.5.10.1")
puts rec.country_short
puts rec.country_long
puts rec.city

puts "------- IPv6 Sample --------"
IP2LocObjIPv6 = IP2Location.new()
IP2LocObjIPv6.open("data/IPV6-COUNTRY.BIN") # Unix like path separator. Must change to '\\' for Windows platform
recIPv6 = IP2LocObjIPv6.get_all("2001:4830:00EA::")
puts recIPv6.country_short
puts recIPv6.country_long
