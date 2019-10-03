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

#include <aws/ec2/model/PurchaseReservedInstancesOfferingRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

PurchaseReservedInstancesOfferingRequest::PurchaseReservedInstancesOfferingRequest() : 
    m_instanceCount(0),
    m_instanceCountHasBeenSet(false),
    m_reservedInstancesOfferingIdHasBeenSet(false),
    m_dryRun(false),
    m_dryRunHasBeenSet(false),
    m_limitPriceHasBeenSet(false),
    m_purchaseTimeHasBeenSet(false)
{
}

Aws::String PurchaseReservedInstancesOfferingRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=PurchaseReservedInstancesOffering&";
  if(m_instanceCountHasBeenSet)
  {
    ss << "InstanceCount=" << m_instanceCount << "&";
  }

  if(m_reservedInstancesOfferingIdHasBeenSet)
  {
    ss << "ReservedInstancesOfferingId=" << StringUtils::URLEncode(m_reservedInstancesOfferingId.c_str()) << "&";
  }

  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << std::boolalpha << m_dryRun << "&";
  }

  if(m_limitPriceHasBeenSet)
  {
    m_limitPrice.OutputToStream(ss, "LimitPrice");
  }

  if(m_purchaseTimeHasBeenSet)
  {
    ss << "PurchaseTime=" << StringUtils::URLEncode(m_purchaseTime.ToGmtString(DateFormat::ISO_8601).c_str()) << "&";
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  PurchaseReservedInstancesOfferingRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
