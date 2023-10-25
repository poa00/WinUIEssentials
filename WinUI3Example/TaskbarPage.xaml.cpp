// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "TaskbarPage.xaml.h"
#if __has_include("TaskbarPage.g.cpp")
#include "TaskbarPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3Example::implementation
{
    TaskbarPage::TaskbarPage()
    {
        InitializeComponent();
    }

    int32_t TaskbarPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TaskbarPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void TaskbarPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
