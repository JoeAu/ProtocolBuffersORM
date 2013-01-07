// Author: glsensor@gmail.com (Joe Au)
// To Extended Protocol Buffers, increased the Entity and Object-relational mapping

#include <string>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace java {

	void AddEntityORM(io::Printer* printer, const Descriptor* descriptor_);
	void AddEnumORM(io::Printer* printer, const EnumDescriptor* descriptor_);

}  // namespace java
}  // namespace compiler
}  // namespace protobuf

}  // namespace google
