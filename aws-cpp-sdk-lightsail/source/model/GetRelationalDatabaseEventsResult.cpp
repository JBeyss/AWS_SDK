﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/lightsail/model/GetRelationalDatabaseEventsResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::Lightsail::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

GetRelationalDatabaseEventsResult::GetRelationalDatabaseEventsResult()
{
}

GetRelationalDatabaseEventsResult::GetRelationalDatabaseEventsResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

GetRelationalDatabaseEventsResult& GetRelationalDatabaseEventsResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("relationalDatabaseEvents"))
  {
    Array<JsonView> relationalDatabaseEventsJsonList = jsonValue.GetArray("relationalDatabaseEvents");
    for(unsigned relationalDatabaseEventsIndex = 0; relationalDatabaseEventsIndex < relationalDatabaseEventsJsonList.GetLength(); ++relationalDatabaseEventsIndex)
    {
      m_relationalDatabaseEvents.push_back(relationalDatabaseEventsJsonList[relationalDatabaseEventsIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("nextPageToken"))
  {
    m_nextPageToken = jsonValue.GetString("nextPageToken");

  }



  return *this;
}
