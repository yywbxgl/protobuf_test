

protobuff version: 3.8.0



## 编译命令
```
# 编译proto文件，生成c++头文件
protoc --cpp_out=./ addressbook.proto

# 编译应用程序  
g++ create_person.cc  addressbook.pb.cc  /usr/local/lib/libprotobuf.a -std=c++11 -pthread -I/usr/local/include -o create_person

g++ list_people.cc  addressbook.pb.cc  /usr/local/lib/libprotobuf.a -std=c++11 -pthread -I/usr/local/include -o list_people

g++ add_person.cc  addressbook.pb.cc  /usr/local/lib/libprotobuf.a -std=c++11 -pthread -I/usr/local/include -o add_person

g++ modify_person.cc  addressbook.pb.cc  /usr/local/lib/libprotobuf.a -std=c++11 -pthread -I/usr/local/include -o modify_person

```


## 运行命令
```
./create_person  my_book

./list_people  my_book

./add_people  my_book  my_book2

```