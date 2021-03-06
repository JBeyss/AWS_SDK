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

#pragma once
#include <aws/macie2/Macie2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/macie2/model/UnprocessedAccount.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace Macie2
{
namespace Model
{
  class AWS_MACIE2_API DeclineInvitationsResult
  {
  public:
    DeclineInvitationsResult();
    DeclineInvitationsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    DeclineInvitationsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline const Aws::Vector<UnprocessedAccount>& GetUnprocessedAccounts() const{ return m_unprocessedAccounts; }

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline void SetUnprocessedAccounts(const Aws::Vector<UnprocessedAccount>& value) { m_unprocessedAccounts = value; }

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline void SetUnprocessedAccounts(Aws::Vector<UnprocessedAccount>&& value) { m_unprocessedAccounts = std::move(value); }

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline DeclineInvitationsResult& WithUnprocessedAccounts(const Aws::Vector<UnprocessedAccount>& value) { SetUnprocessedAccounts(value); return *this;}

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline DeclineInvitationsResult& WithUnprocessedAccounts(Aws::Vector<UnprocessedAccount>&& value) { SetUnprocessedAccounts(std::move(value)); return *this;}

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline DeclineInvitationsResult& AddUnprocessedAccounts(const UnprocessedAccount& value) { m_unprocessedAccounts.push_back(value); return *this; }

    /**
     * <p>An array of objects, one for each account whose invitation hasn't been
     * declined. Each object identifies the account and explains why the request hasn't
     * been processed for that account.</p>
     */
    inline DeclineInvitationsResult& AddUnprocessedAccounts(UnprocessedAccount&& value) { m_unprocessedAccounts.push_back(std::move(value)); return *this; }

  private:

    Aws::Vector<UnprocessedAccount> m_unprocessedAccounts;
  };

} // namespace Model
} // namespace Macie2
} // namespace Aws
