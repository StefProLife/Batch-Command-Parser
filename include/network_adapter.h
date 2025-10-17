#include "Inetwork_adapter.h"

class NetworkAdapter : public INetworkAdapter
{
public:
    NetworkAdapter(ReaderPtr reader, size_t countPackageInBolock);
public:
    void ReadPackage() override;
    size_t GetCountPackageInBolock() override;
    const ReaderPtr& GetReader() const override;
private:
    ReaderPtr _reader;
    size_t _countPackageInBolock;
};