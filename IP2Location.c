/* Copyright (C) 2005-2010 IP2Location.com
 * All Rights Reserved
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; If not, see <http://www.gnu.org/licenses/>.
 */

#include "ruby.h"
#include "IP2Location.h"

VALUE cIP2Location;
VALUE cIP2LocRec;

static void copyRecord (IP2LocationRecord* cRec, IP2LocationRecord* pRec) {
	cRec->country_short = pRec->country_short;
	cRec->country_long = pRec->country_long;
	cRec->region = pRec->region;
	cRec->city = pRec->city;
	cRec->isp = pRec->isp;
	cRec->latitude = pRec->latitude;
	cRec->longitude = pRec->longitude;
	cRec->domain = pRec->domain;
	cRec->zipcode = pRec->zipcode;
	cRec->timezone = pRec->timezone;
	cRec->netspeed = pRec->netspeed;
	cRec->iddcode = pRec->iddcode;
	cRec->areacode = pRec->areacode;
	cRec->weatherstationcode = pRec->weatherstationcode;
	cRec->weatherstationname = pRec->weatherstationname;
	cRec->mcc = pRec->mcc;
	cRec->mnc = pRec->mnc;
	cRec->mobilebrand = pRec->mobilebrand;
}

static void free_record (IP2LocationRecord* pFree)
{
	IP2Location_free_record(pFree);
}

static VALUE rb_cIP2LocRec_init (VALUE klass) 
{	
	// todo...
}

static VALUE rb_cIP2LocRec_new (VALUE klass, IP2LocationRecord* pRec) 
{	
	VALUE rec;
	IP2LocationRecord *cRec;
	rec = Data_Make_Struct(klass, IP2LocationRecord, 0, free_record, cRec);
	copyRecord(cRec, pRec);
	rb_obj_call_init(rec, 0, 0);
	return rec;
}

static void rb_IP2Location_open(VALUE class, VALUE dbFile)
{
        IP2Location *IP2LocationObj;
	VALUE ipObj;
	VALUE dbFile_for_cstr_cast = rb_str_dup(dbFile);
	
	rb_str_modify(dbFile_for_cstr_cast);
	
        //IP2LocationObj = IP2Location_open(STR2CSTR(dbFile));
	IP2LocationObj = IP2Location_open(StringValuePtr(dbFile_for_cstr_cast));
	ipObj = Data_Wrap_Struct(0, 0, 0, IP2LocationObj);

	rb_iv_set(class, "@ip2loc", ipObj);
}

static VALUE rb_IP2Location_get_country_short(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_country_long(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_country_short(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_country_long(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
		
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_country_long(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_country_long(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_region(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_region(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_region(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_city(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_city(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_city(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_isp(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_isp(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_isp(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_latitude(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_latitude(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_latitude(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_longitude(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_longitude(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_longitude(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_domain(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_domain(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_domain(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_zipcode(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_zipcode(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_zipcode(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_timezone(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_timezone(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_timezone(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_netspeed(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);

	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_netspeed(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_netspeed(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_iddcode(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);

	rb_str_modify(ipaddr_for_cstr_cast);

	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_iddcode(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_iddcode(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_areacode(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);

	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_areacode(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_areacode(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_weatherstationcode(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_weatherstationcode(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_weatherstationcode(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_weatherstationname(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);

	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_weatherstationname(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_weatherstationname(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_mcc(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_mcc(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_mcc(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_mnc(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);

	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_mnc(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_mnc(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_mobilebrand(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_mobilebrand(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_mobilebrand(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}

static VALUE rb_IP2Location_get_all(VALUE class, VALUE ipaddr)
{
	IP2Location* IP2LocationObj = NULL;
	IP2LocationRecord* pRec = NULL;
	VALUE rRec;
	VALUE ipObj = rb_iv_get(class, "@ip2loc");
	VALUE ipaddr_for_cstr_cast = rb_str_dup(ipaddr);
	
	rb_str_modify(ipaddr_for_cstr_cast);
	
	Data_Get_Struct(ipObj, IP2Location,  IP2LocationObj);
	//pRec = IP2Location_get_all(IP2LocationObj, STR2CSTR(ipaddr));
	pRec = IP2Location_get_all(IP2LocationObj, StringValuePtr(ipaddr_for_cstr_cast));
	return rb_cIP2LocRec_new(cIP2LocRec, pRec);
}


static VALUE rb_IP2Location_init(VALUE class)
{
	// todo...
}

static VALUE rb_cIP2LocRec_country_short (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->country_short);
}

static VALUE rb_cIP2LocRec_country_long (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->country_long);
}

static VALUE rb_cIP2LocRec_region (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->region);
}

static VALUE rb_cIP2LocRec_city (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->city);
}

static VALUE rb_cIP2LocRec_isp (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->isp);
}

static VALUE rb_cIP2LocRec_latitude (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_float_new(pRec->latitude);
}

static VALUE rb_cIP2LocRec_longitude (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_float_new(pRec->longitude);
}

static VALUE rb_cIP2LocRec_domain (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->domain);
}

static VALUE rb_cIP2LocRec_zipcode (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->zipcode);
}

static VALUE rb_cIP2LocRec_timezone (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->timezone);
}

static VALUE rb_cIP2LocRec_netspeed (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->netspeed);
}

static VALUE rb_cIP2LocRec_iddcode (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->iddcode);
}

static VALUE rb_cIP2LocRec_areacode (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->areacode);
}

static VALUE rb_cIP2LocRec_weatherstationcode (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->weatherstationcode);
}

static VALUE rb_cIP2LocRec_weatherstationname (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->weatherstationname);
}

static VALUE rb_cIP2LocRec_mcc (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->mcc);
}

static VALUE rb_cIP2LocRec_mnc (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->mnc);
}

static VALUE rb_cIP2LocRec_mobilebrand (VALUE klass) {	
	IP2LocationRecord *pRec;
	Data_Get_Struct(klass, IP2LocationRecord, pRec);
	return rb_str_new2(pRec->mobilebrand);
}

void Init_IP2Location() {
  
  /* IP2Location class definition */
  cIP2Location = rb_define_class("IP2Location", rb_cObject);
  rb_define_method(cIP2Location, "initialize", rb_IP2Location_init, 0);
  rb_define_method(cIP2Location, "open", rb_IP2Location_open, 1);
  rb_define_method(cIP2Location, "get_country_short", rb_IP2Location_get_country_short, 1);
  rb_define_method(cIP2Location, "get_country_long", IP2Location_get_country_long, 1);
  rb_define_method(cIP2Location, "get_region", rb_IP2Location_get_region, 1);
  rb_define_method(cIP2Location, "get_city", rb_IP2Location_get_city, 1);
  rb_define_method(cIP2Location, "get_isp", rb_IP2Location_get_isp, 1);
  rb_define_method(cIP2Location, "get_latitude", rb_IP2Location_get_latitude, 1);
  rb_define_method(cIP2Location, "get_longitude", rb_IP2Location_get_longitude, 1);
  rb_define_method(cIP2Location, "get_domain", rb_IP2Location_get_domain, 1);
  rb_define_method(cIP2Location, "get_zipcode", rb_IP2Location_get_zipcode, 1);
  rb_define_method(cIP2Location, "get_timezone", rb_IP2Location_get_timezone, 1);
  rb_define_method(cIP2Location, "get_netspeed", rb_IP2Location_get_netspeed, 1);
  rb_define_method(cIP2Location, "get_iddcode", rb_IP2Location_get_iddcode, 1);
  rb_define_method(cIP2Location, "get_areacode", rb_IP2Location_get_areacode, 1);
  rb_define_method(cIP2Location, "get_weatherstationcode", rb_IP2Location_get_weatherstationcode, 1);
  rb_define_method(cIP2Location, "get_weatherstationname", rb_IP2Location_get_weatherstationname, 1);
  rb_define_method(cIP2Location, "get_mcc", rb_IP2Location_get_mcc, 1);
  rb_define_method(cIP2Location, "get_mnc", rb_IP2Location_get_mnc, 1);
  rb_define_method(cIP2Location, "get_mobilebrand", rb_IP2Location_get_mobilebrand, 1);
  rb_define_method(cIP2Location, "get_all", rb_IP2Location_get_all, 1);
  
  /* IP2LocationRecord class definition */
  cIP2LocRec = rb_define_class("IP2LocationRecord", rb_cObject);
  rb_define_singleton_method(cIP2LocRec, "new", rb_cIP2LocRec_new, 0);
  rb_define_method(cIP2LocRec, "initialize", rb_cIP2LocRec_init, 0);
  rb_define_method(cIP2LocRec, "country_short", rb_cIP2LocRec_country_short, 0);
  rb_define_method(cIP2LocRec, "country_long", rb_cIP2LocRec_country_long, 0);
  rb_define_method(cIP2LocRec, "region", rb_cIP2LocRec_region, 0);
  rb_define_method(cIP2LocRec, "city", rb_cIP2LocRec_city, 0);
  rb_define_method(cIP2LocRec, "isp", rb_cIP2LocRec_isp, 0);
  rb_define_method(cIP2LocRec, "latitude", rb_cIP2LocRec_latitude, 0);
  rb_define_method(cIP2LocRec, "longitude", rb_cIP2LocRec_longitude, 0);
  rb_define_method(cIP2LocRec, "domain", rb_cIP2LocRec_domain, 0);
  rb_define_method(cIP2LocRec, "zipcode", rb_cIP2LocRec_zipcode, 0);
  rb_define_method(cIP2LocRec, "timezone", rb_cIP2LocRec_timezone, 0);
	rb_define_method(cIP2LocRec, "netspeed", rb_cIP2LocRec_netspeed, 0);
	rb_define_method(cIP2LocRec, "iddcode", rb_cIP2LocRec_iddcode, 0);
	rb_define_method(cIP2LocRec, "areacode", rb_cIP2LocRec_areacode, 0);
	rb_define_method(cIP2LocRec, "weatherstationcode", rb_cIP2LocRec_weatherstationcode, 0);
	rb_define_method(cIP2LocRec, "weatherstationname", rb_cIP2LocRec_weatherstationname, 0);
	rb_define_method(cIP2LocRec, "mcc", rb_cIP2LocRec_mcc, 0);
	rb_define_method(cIP2LocRec, "mnc", rb_cIP2LocRec_mnc, 0);
	rb_define_method(cIP2LocRec, "mobilebrand", rb_cIP2LocRec_mobilebrand, 0);
}                                         
  
  
  
