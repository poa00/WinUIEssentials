#pragma once

#include "ProgressBarEx.g.h"
#include "TemplateControlHelper.hpp"
#include <winrt/Microsoft.UI.Composition.h>

namespace winrt::WinUI3Example::implementation
{
    struct ProgressBarEx : ProgressBarExT<ProgressBarEx>, TemplateControlHelper<ProgressBarEx>
    {
        ProgressBarEx() = default;

        void OnApplyTemplate();
        winrt::Windows::UI::Color Color();
        void Color(winrt::Windows::UI::Color value);
        static winrt::Microsoft::UI::Xaml::DependencyProperty ColorProperty();

        double Percent();
        void Percent(double value);
        static winrt::Microsoft::UI::Xaml::DependencyProperty PercentProperty();
    private:
        static void onColorPropertyChanged(
            winrt::Microsoft::UI::Xaml::DependencyObject const& d,
            winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e
        );

        static void onPercentPropertyChanged(
            winrt::Microsoft::UI::Xaml::DependencyObject const& d,
            winrt::Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e
        );
        winrt::Microsoft::UI::Composition::Compositor m_compositor{ nullptr };
        winrt::Microsoft::UI::Composition::CompositionColorGradientStop m_gradients[4]{ nullptr, nullptr, nullptr, nullptr };
        winrt::Microsoft::UI::Composition::SpriteVisual m_spriteVisual{ nullptr };

        void setColor();
        void setSpriteSize();
        static winrt::Microsoft::UI::Xaml::DependencyProperty s_colorProperty;
        static winrt::Microsoft::UI::Xaml::DependencyProperty s_percentProperty;
    };
}

namespace winrt::WinUI3Example::factory_implementation
{
    struct ProgressBarEx : ProgressBarExT<ProgressBarEx, implementation::ProgressBarEx>
    {
    };
}
