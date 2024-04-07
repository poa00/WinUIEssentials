#include "pch.h"
#include "UriPage.h"
#if __has_include("UriPage.g.cpp")
#include "UriPage.g.cpp"
#endif
#include <winrt/Windows.System.h>
#include <BuiltInUris.hpp>

using namespace winrt;
using namespace Windows::UI::Xaml;



//class ScreenClip
//{
//    template<typename Value = std::wstring_view>
//    struct QueryBase
//    {
//        std::wstring_view name;
//        Value value;
//    };
//    struct TypeImpl : QueryBase<std::wstring_view>
//    {
//        constexpr TypeImpl(std::wstring_view type) : QueryBase{ L"type", type } {}
//    };
//public:
//    struct Source : QueryBase<>
//    {
//        constexpr Source(std::wstring_view source) : QueryBase{ L"source", source } {}
//    };
//    struct Type
//    {
//        constexpr static inline TypeImpl Snapshot{ L"snapshot" };
//        constexpr static inline TypeImpl Recording{ L"recording" };
//    };
//    struct DelayInSeconds : QueryBase<int>
//    {
//        constexpr DelayInSeconds(int seconds) : QueryBase{ L"delayInSeconds", seconds } {}
//    };
//};

namespace winrt::UWPExample::implementation
{

    static winrt::Windows::Foundation::IAsyncOperation<bool> Launch()
    {
        //Settings::A;
        return winrt::Windows::System::Launcher::LaunchUriAsync(BuiltInUris::Settings::MobileDevices);
    }
}
