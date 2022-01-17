#include <cookie/cookie.h>

int main()
{
    using namespace cookie;

    log::Info("Berhasil membuat log library!");
    log::Warn("Bahaya, hehehe...");
    log::Error("Ada masalah bang");
    log::SdlError("Ada SDL error bang");
}