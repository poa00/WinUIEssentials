#pragma once

#include "SettingsExpanderPage.g.h"

namespace winrt::UWPExample::implementation
{
    struct SettingsExpanderPage : SettingsExpanderPageT<SettingsExpanderPage>
    {
        SettingsExpanderPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct SettingsExpanderPage : SettingsExpanderPageT<SettingsExpanderPage, implementation::SettingsExpanderPage>
    {
    };
}
