/***
 * Template Method Pattern
 * No virtual function in the public interface (except for the destructor).
 * This is an example for the Non-Virtual Interface Idiom (Non-Virtual Interface)
 * By means of the Non-Virtual Interface Idiom (Non-Virtual Interface) we have ...
☛ ... separated concerns and simplified change (Single Responsible Principle);
☛ ... enabled internal changes with no impact on callers;
☛ ... reduced duplication (Dont Repeat Yourself).
 */


#include <string>

class Blob
{
public:
 std::string name() const { return name_; }
private:
 std::string name_;
};

class WriteCallback
{

};

class ReadCallback
{

};


using uint = unsigned int;


class PersistenceInterface
{
public:
 PersistenceInterface();

 virtual ~PersistenceInterface();

 bool write( const Blob& blob );
 bool write( const Blob& blob, WriteCallback callback );
 bool read ( Blob& blob, uint timeout );
 bool read ( Blob& blob, ReadCallback callback, uint timeout );
 // ...

private:  //virtual in the private
 virtual bool prepperWrite( ) = 0;
 virtual bool doWrite( const Blob& blob ) = 0;
 virtual bool doWrite( const Blob& blob, WriteCallback callback ) = 0;
 virtual bool doRead ( Blob& blob, uint timeout ) = 0;
 virtual bool doRead ( Blob& blob, ReadCallback callback, uint timeout ) = 0;
 // ...
};



void LOG_INFO(char* aa){}
void LOG_ERROR(char* aa){}



bool PersistenceInterface::write( const Blob& blob )
{
 LOG_INFO("log1");
 if(blob.name().empty())
 {
  LOG_ERROR("log error");
 }
 LOG_INFO("log2");


 const bool success = prepperWrite( ) && doWrite( blob );
 return success;
}



class FilePersistence : public PersistenceInterface {
private:
    bool prepperWrite() override {
        LOG_INFO("Preparing to write to file...");
        // File-specific preparation logic
        return true;
    }

    bool doWrite(const Blob& blob) override {
        LOG_INFO("Writing blob to file...");
        // File-specific writing logic
        return true; // Simulate success
    }

    bool doWrite(const Blob& blob, WriteCallback callback) override {
        LOG_INFO("Writing blob to file with callback...");
        // File-specific writing logic with callback
        return true;
    }

    bool doRead(Blob& blob, uint timeout) override {
        LOG_INFO("Reading blob from file...");
        // File-specific reading logic
        return true; // Simulate success
    }

    bool doRead(Blob& blob, ReadCallback callback, uint timeout) override {
        LOG_INFO("Reading blob from file with callback...");
        // File-specific reading logic with callback
        return true;
    }
};
