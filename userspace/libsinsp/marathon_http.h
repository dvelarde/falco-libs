// SPDX-License-Identifier: Apache-2.0
/*
Copyright (C) 2023 The Falco Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/
//
// marathon_http.h
//
#ifndef MINIMAL_BUILD
#pragma once

#if defined(HAS_CAPTURE) && !defined(_WIN32)

#include "curl/curl.h"
#include "uri.h"
#include "mesos_http.h"
#include <memory>

class marathon_http : public mesos_http
{
public:
	typedef std::shared_ptr<marathon_http> ptr_t;

	marathon_http(mesos& m, const uri& url, bool discover_marathon, int timeout_ms = 5000L, const std::string& token = "");

	~marathon_http();

	bool refresh_data();

	std::string get_groups(const std::string& group_id);

private:
	std::string m_data;
};

#endif // HAS_CAPTURE
#endif // MINIMAL_BUILD
