/*
 * Copyright (c) 2023 General Motors GTO LLC
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * SPDX-FileType: SOURCE
 * SPDX-FileCopyrightText: 2023 General Motors GTO LLC
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PROTO_CONVERTER_H_
#define _PROTO_CONVERTER_H_

#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/wrappers.pb.h>
#include <google/protobuf/any.pb.h>

#include <rapidjson/document.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <string>

using namespace google::protobuf;
using namespace rapidjson;

class ProtoConverter {
public:
    //static bool dictToProto(const Value& parentJsonObj, Message& parentProtoObj);
    static Message* dictToProto(const Value& parentJsonObj, Message& parentProtoObj);
    static Value convertMessageToJson(const Message& message, Document& doc);
    static Value convertMessageToDocument(const Message& message, Document& doc);

private:
    static void populateFields(const Value& jsonObj, Message& protoObj);
    static void setFieldValue(Message& protoObj, const FieldDescriptor* fieldDescriptor, const Value& value);
    static Value convertRepeatedFieldToValue(const FieldDescriptor* field, const Message& message, Document& doc);
    static Value convertFieldToValue(const FieldDescriptor* field, const Message& message, Document& doc);
};

#endif /* _PROTO_CONVERTER_H_ */

