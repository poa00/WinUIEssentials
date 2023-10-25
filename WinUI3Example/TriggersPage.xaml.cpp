// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "TriggersPage.xaml.h"
#if __has_include("TriggersPage.g.cpp")
#include "TriggersPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Example::implementation
{
    TriggersPage::TriggersPage()
    {
        InitializeComponent();
    }

    int32_t TriggersPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TriggersPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void TriggersPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
