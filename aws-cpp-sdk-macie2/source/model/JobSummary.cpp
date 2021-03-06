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

#include <aws/macie2/model/JobSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Macie2
{
namespace Model
{

JobSummary::JobSummary() : 
    m_bucketDefinitionsHasBeenSet(false),
    m_createdAtHasBeenSet(false),
    m_jobIdHasBeenSet(false),
    m_jobStatus(JobStatus::NOT_SET),
    m_jobStatusHasBeenSet(false),
    m_jobType(JobType::NOT_SET),
    m_jobTypeHasBeenSet(false),
    m_nameHasBeenSet(false)
{
}

JobSummary::JobSummary(JsonView jsonValue) : 
    m_bucketDefinitionsHasBeenSet(false),
    m_createdAtHasBeenSet(false),
    m_jobIdHasBeenSet(false),
    m_jobStatus(JobStatus::NOT_SET),
    m_jobStatusHasBeenSet(false),
    m_jobType(JobType::NOT_SET),
    m_jobTypeHasBeenSet(false),
    m_nameHasBeenSet(false)
{
  *this = jsonValue;
}

JobSummary& JobSummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("bucketDefinitions"))
  {
    Array<JsonView> bucketDefinitionsJsonList = jsonValue.GetArray("bucketDefinitions");
    for(unsigned bucketDefinitionsIndex = 0; bucketDefinitionsIndex < bucketDefinitionsJsonList.GetLength(); ++bucketDefinitionsIndex)
    {
      m_bucketDefinitions.push_back(bucketDefinitionsJsonList[bucketDefinitionsIndex].AsObject());
    }
    m_bucketDefinitionsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("createdAt"))
  {
    m_createdAt = jsonValue.GetString("createdAt");

    m_createdAtHasBeenSet = true;
  }

  if(jsonValue.ValueExists("jobId"))
  {
    m_jobId = jsonValue.GetString("jobId");

    m_jobIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("jobStatus"))
  {
    m_jobStatus = JobStatusMapper::GetJobStatusForName(jsonValue.GetString("jobStatus"));

    m_jobStatusHasBeenSet = true;
  }

  if(jsonValue.ValueExists("jobType"))
  {
    m_jobType = JobTypeMapper::GetJobTypeForName(jsonValue.GetString("jobType"));

    m_jobTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("name"))
  {
    m_name = jsonValue.GetString("name");

    m_nameHasBeenSet = true;
  }

  return *this;
}

JsonValue JobSummary::Jsonize() const
{
  JsonValue payload;

  if(m_bucketDefinitionsHasBeenSet)
  {
   Array<JsonValue> bucketDefinitionsJsonList(m_bucketDefinitions.size());
   for(unsigned bucketDefinitionsIndex = 0; bucketDefinitionsIndex < bucketDefinitionsJsonList.GetLength(); ++bucketDefinitionsIndex)
   {
     bucketDefinitionsJsonList[bucketDefinitionsIndex].AsObject(m_bucketDefinitions[bucketDefinitionsIndex].Jsonize());
   }
   payload.WithArray("bucketDefinitions", std::move(bucketDefinitionsJsonList));

  }

  if(m_createdAtHasBeenSet)
  {
   payload.WithString("createdAt", m_createdAt.ToGmtString(DateFormat::ISO_8601));
  }

  if(m_jobIdHasBeenSet)
  {
   payload.WithString("jobId", m_jobId);

  }

  if(m_jobStatusHasBeenSet)
  {
   payload.WithString("jobStatus", JobStatusMapper::GetNameForJobStatus(m_jobStatus));
  }

  if(m_jobTypeHasBeenSet)
  {
   payload.WithString("jobType", JobTypeMapper::GetNameForJobType(m_jobType));
  }

  if(m_nameHasBeenSet)
  {
   payload.WithString("name", m_name);

  }

  return payload;
}

} // namespace Model
} // namespace Macie2
} // namespace Aws
