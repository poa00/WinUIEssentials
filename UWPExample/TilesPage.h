#pragma once

#include "TilesPage.g.h"
#include <winrt/Windows.UI.Notifications.h>
#include "TilesBuilder.hpp"

namespace winrt::UWPExample::implementation
{
    using namespace TilesBuilder;
    struct TilesPage : TilesPageT<TilesPage>
    {
        TilesPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

            m_updater.EnableNotificationQueue(true);
        }

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        winrt::Windows::UI::Notifications::TileUpdater m_updater = winrt::Windows::UI::Notifications::TileUpdateManager::CreateTileUpdaterForApplication();
    public:
        winrt::Windows::Foundation::IAsyncAction Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);


        static winrt::hstring GetXml(int selection);

    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct TilesPage : TilesPageT<TilesPage, implementation::TilesPage>
    {
    };
}
