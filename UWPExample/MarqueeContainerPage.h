#pragma once

#include "MarqueeContainerPage.g.h"

namespace winrt::UWPExample::implementation
{
    struct MarqueeContainerPage : MarqueeContainerPageT<MarqueeContainerPage>
    {
        MarqueeContainerPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        static MarqueeBehavior GetBehaviorFromIndex(int value);
        static MarqueeDirection GetDirectionFromIndex(int value);
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct MarqueeContainerPage : MarqueeContainerPageT<MarqueeContainerPage, implementation::MarqueeContainerPage>
    {
    };
}
