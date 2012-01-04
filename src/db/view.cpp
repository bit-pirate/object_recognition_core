/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <object_recognition/db/db.h>
#include <object_recognition/db/view.h>

namespace object_recognition
{
  namespace db
  {
    /** Given a document, returns whether it is in the view, and if so, returns the key and value
     * @param document
     * @param key
     * @param value
     * @return
     */
    bool
    View::GetKey(const or_json::mObject & document, or_json::mValue & key, or_json::mValue & value)
    {
      switch (type_)
      {
        case VIEW_MODEL_WHERE_OBJECT_ID_AND_MODEL_TYPE:
          if (document.find("method")->second == parameters_.find("model_type")->second)
          {
            key = document.find("_id")->second.get_str();
            value = or_json::mValue(document);
            return true;
          }
          break;
      }
      return false;
    }

    /** Set the results to have one specific key
     * @param key
     */
    void
    View::set_key(const Key & key)
    {
      is_key_set_ = true;
      key_ = key;
    }

    /** Set the view to return all results, no matter the key
     */
    void
    View::unset_key()
    {
      is_key_set_ = false;
    }
  }
}
