// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "BadgePage.xaml.h"
#if __has_include("BadgePage.g.cpp")
#include "BadgePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Example::implementation
{
    BadgePage::BadgePage()
    {
        InitializeComponent();
    }

    int32_t BadgePage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void BadgePage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void BadgePage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
