/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2009, Willow Garage, Inc.
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

#ifndef UTILS_H_
#define UTILS_H_

#include "object_recognition/db/db.h"

namespace object_recognition
{
  namespace db
  {
    /** Function that compares the intersection of two JSON trees
     * @param obj1
     * @param obj2
     * @return true if the intersection between the keys have the same values
     */
    bool
    CompareJsonIntersection(const json_spirit::mObject &obj1, const json_spirit::mObject &obj2);

    /** Function filling a DB document for a model with the common attributes
     * @param db the DB where the model will be saved
     * @param collection_name the collection where the model will be saved
     * @param object_id the id of the object for that model
     * @param model_params the parameters of the model
     * @param model_type the type of the model (TOD, Linemod, mesh, however you name it)
     * @return
     */
    Document
    PopulateDoc(const ObjectDb& db, const CollectionName& collection_name, const ObjectId& object_id,
                const std::string& model_params, const std::string& model_type);

    /** Given some parameters, retrieve Documents that are models either of id in model_ids, or with an object_id
     * that is in object_ids and with parameters matching model_json_params
     * @param object_ids
     * @param model_ids
     * @param model_json_params
     * @return
     */
    Documents
    ModelDocuments(ObjectDb &db, const std::string &collection_name, const std::vector<ObjectId> & object_ids,
                   const std::vector<ModelId> & model_ids, const std::string & model_json_params);
  }
}

#endif /* UTILS_H_ */