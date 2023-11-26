#pragma once

#include "IconButton.g.h"
#include "include/TemplateControlHelper.hpp"

namespace winrt::UWPPackage::implementation
{
    struct IconButton : IconButtonT<IconButton>, TemplateControlHelper<IconButton>
    {
        IconButton();

        void OnApplyTemplate();

        winrt::Windows::Foundation::IInspectable Icon();
        void Icon(winrt::Windows::Foundation::IInspectable value);

        static winrt::Windows::UI::Xaml::DependencyProperty IconProperty();

        // Register
        winrt::event_token Click(winrt::Windows::UI::Xaml::RoutedEventHandler const& handler);

        // Revoke with event_token
        void Click(event_token const& cookie);

        void Collapse();
        void Expand();

        bool IsExpanded();
        void IsExpanded(bool value);
        static winrt::Windows::UI::Xaml::DependencyProperty IsExpandedProperty();
    private:
        winrt::event<winrt::Windows::UI::Xaml::RoutedEventHandler> m_handlers;

        static winrt::Windows::UI::Xaml::DependencyProperty m_iconProperty;
        static winrt::Windows::UI::Xaml::DependencyProperty m_isExpandedProperty;
        winrt::Windows::UI::Xaml::Media::Animation::Storyboard m_storyboard{ nullptr };
        winrt::Windows::UI::Xaml::Media::Animation::DoubleAnimation m_widthAnimation{ nullptr };
        winrt::Windows::UI::Xaml::Controls::ContentPresenter m_contentPresenter{ nullptr };
        std::optional<double> m_firstWidth;
        constexpr static std::chrono::milliseconds duration{ 300 };
        bool m_loaded{};
    };
}

namespace winrt::UWPPackage::factory_implementation
{
    struct IconButton : IconButtonT<IconButton, implementation::IconButton>
    {
    };
}
