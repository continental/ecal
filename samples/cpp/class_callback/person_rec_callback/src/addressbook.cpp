/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include "addressbook.h"

Addressbook::Addressbook() {
  // initialize eCAL API
  eCAL::Initialize();

  // set process state
  eCAL::Process::SetState(proc_sev_healthy, proc_sev_level1, "I feel good !");

  // create a subscriber (topic name "person")
  subscriber_ = eCAL::protobuf::CSubscriber<pb::People::Person>("person");

  // add receiver callback
  auto lambda = [this](const char* topic_, const pb::People::Person& msg, long long time_, long long clock_, long long id_) { return this->callback(msg); };
  if (!subscriber_.AddReceiveCallback(lambda)) {
    std::cout << "eCAL subscriber initialization failed\n";
  }

  book_ = std::vector<pb::People::Person>();
}

void Addressbook::spin() {
  while(eCAL::Ok())
  {
    // sleep 100 ms
    eCAL::Process::SleepMS(100);
  }
}

void Addressbook::callback(const pb::People::Person &person_)
{
  std::cout << "Received message\n";
  book_.push_back(person_);

}

void Addressbook::print() {
  std::cout << "Printing results\n";

  for(auto person: this->book_) {
    std::cout << "------------------------------------------" << std::endl;
    std::cout << " CONTENT "                                  << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "person id    : " << person.id()            << std::endl;
    std::cout << "person name  : " << person.name()          << std::endl;
    std::cout << "person stype : " << person.stype()         << std::endl;
    std::cout << "person email : " << person.email()         << std::endl;
    std::cout << "dog.name     : " << person.dog().name()    << std::endl;
    std::cout << "house.rooms  : " << person.house().rooms() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout                                                 << std::endl;
  }
}

class InterruptException : public std::exception
{
 public:
  InterruptException(int s) : S(s) {}
  int S;
};


void sig_to_exception(int s)
{
  throw InterruptException(s);
}


int main(int argc, char **argv)
{
  std::cout << "Initializing Addressbook class\n";

  // Initialize class
  Addressbook addressbook = Addressbook();

  // Setup Ctrl+C catcher
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = sig_to_exception;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);

  try
  {
    std::cout << "Waiting for messages\n";
    addressbook.spin();
  }
  catch(InterruptException& e)
  {
    addressbook.print();
    eCAL::Finalize();
    return(0);
  }

  return(0);

}
