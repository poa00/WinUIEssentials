// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "SettingsExpanderPage.xaml.h"
#if __has_include("SettingsExpanderPage.g.cpp")
#include "SettingsExpanderPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Example::implementation
{
    SettingsExpanderPage::SettingsExpanderPage()
    {
        InitializeComponent();
    }

    int32_t SettingsExpanderPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SettingsExpanderPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void SettingsExpanderPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
