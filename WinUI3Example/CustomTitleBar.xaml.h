#pragma once
#include "WindowEx.h"
#include "CustomTitleBar.g.h"


namespace winrt::WinUI3Example::implementation
{
    struct CustomTitleBar : winrt::Microsoft::UI::Xaml::Markup::ComponentConnectorT<CustomTitleBarT<CustomTitleBar>>
    {
        CustomTitleBar()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void AppTitleBar_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::WinUI3Example::factory_implementation
{
    struct CustomTitleBar : CustomTitleBarT<CustomTitleBar, implementation::CustomTitleBar>
    {
    };
}
