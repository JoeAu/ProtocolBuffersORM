ProtocolBuffersORM
==================
Author: glsensor@gmail.com (Joe Au)
To Extended Protocol Buffers, increased the entity and Object-relational mapping

================================================================================
This project need protobuf-2.5.0rc1

How to Building?

1) Unzip protobuf-2.5.0rc1.zip;
2) Copy src\ to protobuf-2.5.0rc1\src directory;
3) Building your protoc.exe;

How to Using?
1) protoc -I=./ --java_out=./ <your.proto file>;
2) .proto example;

package com.google.protobuf.test;

message PBModel {
  required bytes b = 1;
	required bool bo = 2;
	required sint32 i = 3;
	required sint64 l = 4;
	required float f = 5;
	required double d = 6;

	required PBEnum1 e = 7; 
	required string str = 8;
	required PBModel1 model1 = 9;
	required PBModel2 model2 = 10;

	repeated bytes Arrayb = 11;
	repeated bool Arraybo = 12 [packed=true];
	repeated sint32 Arrayi = 13 [packed=true];
	repeated sint64 Arrayl = 14 [packed=true];
	repeated float Arrayf = 15 [packed=true];
	repeated double Arrayd = 16 [packed=true];
	
	repeated PBEnum1 Arraye = 17;
	repeated string Arraystr = 18;
	repeated PBModel1 Arraymodel1 = 19;
}

enum PBEnum1 {
	xxx = 0;
	ccc = 1;
	yyy = 2;
}

message PBModel1 {
	required string str1 = 1;
}

message PBModel2 {
	required sint32 pid = 1;
}

3) Using in your Java project;

// SerializeEntity
ModelA.PBModel.PBModelEntity model = new ModelA.PBModel.PBModelEntity();
// ...Assignment and do something
ModelA.PBModel pbModel = ModelA.PBModel.SerializeEntity(model);
byte[] buffer = pbModel.toByteArray();

//DeserializeEntity
ModelA.PBModel pbModel2 = ModelA.PBModel.parseFrom(buffer);
ModelA.PBModel.PBModelEntity model2 = ModelA.PBModel.DeserializeEntity(pbModel2);
// ...do something


================================================================================


