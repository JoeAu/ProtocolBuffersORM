ProtocolBuffersORM
==================

Author: glsensor@gmail.com (Joe Au)

To extended Protocol Buffers, increased the entity and Object-relational mapping

================================================================================

1) This project need protobuf-2.5.0rc1

2) How to building?

1. Unzip protobuf-2.5.0rc1.zip;

2. Copy src\ to protobuf-2.5.0rc1\src directory;

3. Build your protoc.exe;

3) How to using?

1. protoc -I=./ --java_out=./ your.proto file;

2. .proto example;

<pre>
<code>
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
</code>
</pre>

4) Using in your java project;

<pre>
<code>
// SerializeEntity
ModelA.PBModel.PBModelEntity model = new ModelA.PBModel.PBModelEntity();
// ...Assignment and do something
ModelA.PBModel pbModel = ModelA.PBModel.SerializeEntity(model);
byte[] buffer = pbModel.toByteArray();

//DeserializeEntity
ModelA.PBModel pbModel2 = ModelA.PBModel.parseFrom(buffer);
ModelA.PBModel.PBModelEntity model2 = ModelA.PBModel.DeserializeEntity(pbModel2);
// ...do something
</code>
</pre>
