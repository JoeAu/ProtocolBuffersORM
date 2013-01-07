
// Author: glsensor@gmail.com (Joe Au)
// To Extended Protocol Buffers, increased the Entity and Object-relational mapping

#include <google/protobuf/compiler/java/java_helpers.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/compiler/java/java_entity.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace java {

const string JavaTypeName(const FieldDescriptor* field) {
  JavaType type = GetJavaType(field);
  if(field->is_repeated()) {
	  switch (type) {
		case JAVATYPE_INT    : return "int[]";
		case JAVATYPE_LONG   : return "long[]";
		case JAVATYPE_FLOAT  : return "float[]";
		case JAVATYPE_DOUBLE : return "double[]";
		case JAVATYPE_BOOLEAN: return "boolean[]";
		case JAVATYPE_STRING : return "java.lang.String[]";
		case JAVATYPE_BYTES  : return "byte[][]";
		case JAVATYPE_ENUM   : return ClassName(field->enum_type()) + "." + field->enum_type()->name() + "Entity[]";
		case JAVATYPE_MESSAGE: return ClassName(field->message_type()) + "." + field->message_type()->name() + "Entity[]";
	  }
  } else {
	  switch (type) {
		case JAVATYPE_INT    : return "int";
		case JAVATYPE_LONG   : return "long";
		case JAVATYPE_FLOAT  : return "float";
		case JAVATYPE_DOUBLE : return "double";
		case JAVATYPE_BOOLEAN: return "boolean";
		case JAVATYPE_STRING : return "java.lang.String";
		case JAVATYPE_BYTES  : return "byte[]";
		case JAVATYPE_ENUM   : return ClassName(field->enum_type()) + "." + field->enum_type()->name() + "Entity";
		case JAVATYPE_MESSAGE: return ClassName(field->message_type()) + "." + field->message_type()->name() + "Entity";
	  }
  }
  GOOGLE_LOG(FATAL) << "Can't get here.";
  return NULL;
}

const void SerializeField(io::Printer* printer, const FieldDescriptor* field) {
  string capitalized_name = UnderscoresToCapitalizedCamelCase(field);
  string name = field->name();
  string number = SimpleItoa(field->number());
  string fullName;
  string entityName;

  printer->Print("// $name$ number = $number$ \n", "number", number, "name", name);
  JavaType type = GetJavaType(field);
  if(field->is_repeated()) {
	  switch (type) {
		case JAVATYPE_INT    :
			printer->Print("for(int item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_LONG   :
			printer->Print("for(long item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_FLOAT  :
			printer->Print("for(float item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_DOUBLE :
			printer->Print("for(double item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_BOOLEAN:
			printer->Print("for(boolean item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_STRING :
			printer->Print("for(String item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(item);\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_BYTES  :
			printer->Print("for(byte[] item : entity.$name$){\n", "name", name);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$(com.google.protobuf.ByteString.copyFrom(item));\n", "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_ENUM   :
			fullName = ClassName(field->enum_type());
			entityName = fullName + "." + field->enum_type()->name() + "Entity";
			printer->Print("for($entityName$ item : entity.$name$){\n", "name", name, "entityName", entityName);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$($fullName$.valueOf(item.value()));\n", "capitalized_name", capitalized_name, "fullName", fullName);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_MESSAGE:
			fullName = ClassName(field->message_type());
			entityName = fullName + "." + field->message_type()->name() + "Entity";
			printer->Print("for($entityName$ item : entity.$name$){\n", "name", name, "entityName", entityName);
			printer->Indent();
			printer->Print("builder.add$capitalized_name$($fullName$.SerializeEntity(item));\n", "capitalized_name", capitalized_name, "fullName", fullName);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
	  }
  } else {
	  switch (type) {
		case JAVATYPE_INT    :
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_LONG   :
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_FLOAT  :
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_DOUBLE :
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_BOOLEAN:
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_STRING :
			printer->Print("builder.set$capitalized_name$(entity.$name$);\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_BYTES  :
			printer->Print("builder.set$capitalized_name$(com.google.protobuf.ByteString.copyFrom(entity.$name$));\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_ENUM   : 
			fullName = ClassName(field->enum_type());
			entityName = fullName + "." + field->enum_type()->name() + "Entity";
			printer->Print("builder.set$capitalized_name$($fullName$.valueOf(entity.$name$.value()));\n\n", "capitalized_name", capitalized_name, "name", name, "fullName", fullName);
			break;
		case JAVATYPE_MESSAGE: 
			fullName = ClassName(field->message_type());
			entityName = fullName + "." + field->message_type()->name() + "Entity";
			printer->Print("builder.set$capitalized_name$($fullName$.SerializeEntity(entity.$name$));\n\n", "capitalized_name", capitalized_name, "name", name, "fullName", fullName);
			break;
	  }
  }
}

const void DeserializeField(io::Printer* printer, const FieldDescriptor* field) {
  string capitalized_name = UnderscoresToCapitalizedCamelCase(field);
  string name = field->name();
  string number = SimpleItoa(field->number());
  string fullName;
  string entityName;

  printer->Print("// $name$ number = $number$ \n", "number", number, "name", name);
  JavaType type = GetJavaType(field);
  if(field->is_repeated()) {
	  switch (type) {
		case JAVATYPE_INT    :
			printer->Print("entity.$name$ = new int[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_LONG   :
			printer->Print("entity.$name$ = new long[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_FLOAT  :
			printer->Print("entity.$name$ = new float[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_DOUBLE :
			printer->Print("entity.$name$ = new double[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_BOOLEAN:
			printer->Print("entity.$name$ = new boolean[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_STRING :
			printer->Print("entity.$name$ = new String[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i);\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_BYTES  :
			printer->Print("entity.$name$ = new byte[stream.get$capitalized_name$Count()][];\n", "name", name, "capitalized_name", capitalized_name);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = stream.get$capitalized_name$(i).toByteArray();\n", "name", name, "capitalized_name", capitalized_name);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_ENUM   :
			fullName = ClassName(field->enum_type());
			entityName = fullName + "." + field->enum_type()->name() + "Entity";
			printer->Print("entity.$name$ = new $entityName$[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name, "entityName", entityName);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = $entityName$.valueOf(stream.get$capitalized_name$(i).getNumber());\n\n", "capitalized_name", capitalized_name, "name", name, "entityName", entityName);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
		case JAVATYPE_MESSAGE:
			fullName = ClassName(field->message_type());
			entityName = fullName + "." + field->message_type()->name() + "Entity";
			printer->Print("entity.$name$ = new $entityName$[stream.get$capitalized_name$Count()];\n", "name", name, "capitalized_name", capitalized_name, "entityName", entityName);
			printer->Print("for(int i=0;i<entity.$name$.length;++i){\n", "name", name);
			printer->Indent();
			printer->Print("entity.$name$[i] = $fullName$.DeserializeEntity(stream.get$capitalized_name$(i));\n\n", "capitalized_name", capitalized_name, "name", name, "fullName", fullName);
			printer->Outdent();
			printer->Print("}\n\n");
			break;
	  }
  } else {
	  switch (type) {
		case JAVATYPE_INT    :
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_LONG   :
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_FLOAT  :
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_DOUBLE :
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_BOOLEAN:
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_STRING :
			printer->Print("entity.$name$ = stream.get$capitalized_name$();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_BYTES  :
			printer->Print("entity.$name$ = stream.get$capitalized_name$().toByteArray();\n\n", "capitalized_name", capitalized_name, "name", name);
			break;
		case JAVATYPE_ENUM   : 
			fullName = ClassName(field->enum_type());
			entityName = fullName + "." + field->enum_type()->name() + "Entity";
			printer->Print("entity.$name$ = $entityName$.valueOf(stream.get$capitalized_name$().getNumber());\n\n", "capitalized_name", capitalized_name, "name", name, "entityName", entityName);
			break;
		case JAVATYPE_MESSAGE: 
			fullName = ClassName(field->message_type());
			entityName = fullName + "." + field->message_type()->name() + "Entity";
			printer->Print("entity.$name$ = $fullName$.DeserializeEntity(stream.get$capitalized_name$());\n\n", "capitalized_name", capitalized_name, "name", name, "fullName", fullName);
			break;
	  }
  }
}

void AddEntityORM(io::Printer* printer, const Descriptor* descriptor_) {
	string classname = descriptor_->name();
	string fullName = ClassName(descriptor_);
	string entityName = fullName + "." + descriptor_->name() + "Entity";
	string builderName = fullName + ".Builder";

	// Class
	printer->Print(
	  "\n"
	  "// $classname$ Entity \n",
	  "classname", classname);
	printer->Print(
	"public static class $classname$Entity {\n", "classname", classname);
	printer->Indent();
	for (int i = 0; i < descriptor_->field_count(); i++) {
		const FieldDescriptor* field = descriptor_->field(i);
		printer->Print(
			"\n"
			"// number = $num$ \n"
			"public $type$ $fieldname$; \n", 
			"num", SimpleItoa(field->number()),
			"type", JavaTypeName(field), 
			"fieldname", field->name()
			);
	}
	printer->Outdent();
	printer->Print("}\n");

	// Serialize
	printer->Print(
	  "\n"
	  "// $classname$ Serialize \n",
	  "classname", classname);
	printer->Print(
	"public static $fullName$ SerializeEntity($entityName$ entity) {\n", "entityName", entityName, "fullName", fullName);
	printer->Indent();
	printer->Print("$builderName$ builder = $fullName$.newBuilder(); \n", "fullName", fullName, "builderName", builderName);
	for (int i = 0; i < descriptor_->field_count(); i++) {
		const FieldDescriptor* field = descriptor_->field(i);
		SerializeField(printer, field);
	}
	printer->Print("return builder.build();\n");
	printer->Outdent();
	printer->Print("}\n");

	// Deserialize
	printer->Print(
	  "\n"
	  "// $classname$ Deserialize \n",
	  "classname", classname);
	printer->Print(
	"public static $entityName$ DeserializeEntity($fullName$ stream) {\n", "entityName", entityName, "fullName", fullName);
	printer->Indent();
	printer->Print("$entityName$ entity = new $entityName$(); \n", "entityName", entityName);
	for (int i = 0; i < descriptor_->field_count(); i++) {
		const FieldDescriptor* field = descriptor_->field(i);
		DeserializeField(printer, field);
	}
	printer->Print("return entity;\n");
	printer->Outdent();
	printer->Print("}\n\n");
}


void AddEnumORM(io::Printer* printer, const EnumDescriptor* descriptor_) {
	string classname = descriptor_->name();
	string fullName = descriptor_->full_name();
	string entityName = descriptor_->full_name() + "." + descriptor_->name() + "Entity";
	string builderName = descriptor_->full_name() + ".Builder";

	// enum
	printer->Print(
	  "\n"
	  "// $classname$ Entity \n",
	  "classname", classname);
	printer->Print(
	"public enum $classname$Entity {\n\n", "classname", classname);
	printer->Indent();
	for (int i = 0; i < descriptor_->value_count(); i++) {
		const EnumValueDescriptor* value = descriptor_->value(i);
		printer->Print("$name$($num$),\n", "name", value->name(), "num", SimpleItoa(value->number()));
	}
	printer->Print(";\n\n");

	printer->Print("private int value = 0;\n\n");

	printer->Print("private $classname$Entity(int value) {\n", "classname", classname);
	printer->Indent();
	printer->Print("this.value = value;\n");
	printer->Outdent();
	printer->Print("}\n\n");

	printer->Print("public int value() {\n");
	printer->Indent();
	printer->Print("return this.value;\n");
	printer->Outdent();
	printer->Print("}\n\n");

	printer->Print("public static $classname$Entity valueOf(int value) {\n", "classname", classname);
	printer->Indent();
	printer->Print("switch (value) {\n");
	for (int i = 0; i < descriptor_->value_count(); i++) {
		const EnumValueDescriptor* value = descriptor_->value(i);
		printer->Print("case $num$:\n", "num", SimpleItoa(value->number()));
		printer->Indent();
		printer->Print("return $name$;\n", "name", value->name());
		printer->Outdent();
	}
	printer->Print("}\n");
	printer->Print("return null;\n");
	printer->Outdent();
	printer->Print("}\n\n");

	printer->Outdent();
	printer->Print("}\n\n");

}

}  // namespace java
}  // namespace compiler
}  // namespace protobuf
}  // namespace google
