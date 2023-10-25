// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "TriggersPage.g.h"

namespace winrt::WinUI3Example::implementation
{
    struct TriggersPage : TriggersPageT<TriggersPage>
    {
        TriggersPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinUI3Example::factory_implementation
{
    struct TriggersPage : TriggersPageT<TriggersPage, implementation::TriggersPage>
    {
    };
}
