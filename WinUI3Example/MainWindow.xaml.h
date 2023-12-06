// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "WindowEx.h"
#include "MainWindow.g.h"
#include <ranges>

#include <winrt/Microsoft.UI.Xaml.Markup.h>

namespace winrt::WinUI3Example::implementation
{
    struct MainWindow : winrt::Microsoft::UI::Xaml::Markup::ComponentConnectorT<MainWindowT<MainWindow>>
    {
        MainWindow();

        void NavigationView_SelectionChanged(
            winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender,
            winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args);

        winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> Pages()
        {
            std::vector<winrt::Windows::Foundation::IInspectable> pages;
            std::ranges::transform(
                s_page,
                std::back_inserter(pages),
                [](auto const& p) { return winrt::box_value(p.first); }
            );
            return winrt::single_threaded_vector(std::move(pages));
        }
    private:
        static inline std::unordered_map<winrt::hstring, winrt::Windows::UI::Xaml::Interop::TypeName> s_page
        {
            {L"ToastPage", winrt::xaml_typename<WinUI3Example::ToastPage>()},
            {L"CursorControllerPage", winrt::xaml_typename<WinUI3Example::CursorControllerPage>()},
            {L"ConvertersPage", winrt::xaml_typename<WinUI3Example::ConvertersPage>()},
            {L"BadgePage", winrt::xaml_typename<WinUI3Example::BadgePage>()},
            {L"TaskbarPage", winrt::xaml_typename<WinUI3Example::TaskbarPage>()},
            {L"TriggersPage", winrt::xaml_typename<WinUI3Example::TriggersPage>()},
            {L"GroupBoxPage", winrt::xaml_typename<WinUI3Example::GroupBoxPage>()},
            /*{L"CharmBarPage", winrt::xaml_typename<WinUI3Example::CharmBarPage>()},*/
            {L"SettingsCardPage", winrt::xaml_typename<WinUI3Example::SettingsCardPage>()},
            {L"SettingsExpanderPage", winrt::xaml_typename<WinUI3Example::SettingsExpanderPage>()},
            {L"DependentValuePage", winrt::xaml_typename<WinUI3Example::DependentValuePage>()},
            {L"MarqueeTextPage", winrt::xaml_typename<WinUI3Example::MarqueeTextPage>()},
            {L"GlphysPage", winrt::xaml_typename<WinUI3Example::GlyphsPage>()},
            {L"TitleBarPage", winrt::xaml_typename<WinUI3Example::TitleBarPage>()},
        };
    };
}

namespace winrt::WinUI3Example::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
