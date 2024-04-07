#pragma once

#include "UriPage.g.h"

namespace winrt::UWPExample::implementation
{
    struct UriPage : UriPageT<UriPage>
    {
        UriPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Uris()
        {
            UWPExample::UriModel model{ L"model1", winrt::Windows::Foundation::Uri{L"ms-settings:"}};
            UWPExample::UriGroup group{ L"group1", winrt::single_threaded_vector(std::vector<winrt::Windows::Foundation::IInspectable>{model}) };
            std::vector<winrt::Windows::Foundation::IInspectable> ret
            {
                group
            };

            return winrt::single_threaded_vector(std::move(ret));
        }
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct UriPage : UriPageT<UriPage, implementation::UriPage>
    {
    };
}
