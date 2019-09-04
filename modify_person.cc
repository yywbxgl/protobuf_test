#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "addressbook.pb.h"

using namespace std;


// This function modify the email address
void modify(tutorial::AddressBook& address_book) {
  for (int i = 0; i < address_book.people_size(); i++) 
  {
    // 必须使用mutable方式，否则会编译错误，内存对象为const，无法set value
    tutorial::Person* person = address_book.mutable_people(i);

    cout << "Person ID: " << person->id() << endl;
    cout << "  Name: " << person->name() << endl;
    if (person->email() != "") {
      cout << "  E-mail address: " << person->email() << endl;
      person->set_email("1231231123@123.com");  
    }
  }
}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 3) {
    cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE   OUTPUT_FILE" << endl;
    return -1;
  }

  tutorial::AddressBook address_book;

  {
    // Read the existing address book.
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    } else if (!address_book.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }
  }

  // Add an address.
  modify(address_book);

  {
    // Write the new address book back to disk.
    fstream output(argv[2], ios::out | ios::trunc | ios::binary);
    if (!address_book.SerializeToOstream(&output)) {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
