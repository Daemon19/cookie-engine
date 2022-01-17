#include <cookie/cookie.h>

int main()
{
    using namespace cookie;

    Initializer::InitSdl(Initializer::kInitVideo);
    log::Info("Berhasil menginisialisasi SDL");

    log::Info("Berhasil membuat log library!");
    log::Warn("Bahaya, hehehe...");
    log::Error("Ada masalah bang");
    log::SdlError("Ada SDL error bang");
}