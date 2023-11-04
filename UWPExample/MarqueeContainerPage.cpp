#include "pch.h"
#include "MarqueeContainerPage.h"
#if __has_include("MarqueeContainerPage.g.cpp")
#include "MarqueeContainerPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPExample::implementation
{
	MarqueeBehavior MarqueeContainerPage::GetBehaviorFromIndex(int value)
	{
		switch (value)
		{
		case 0: return MarqueeBehavior::Ticker;
		case 1: return MarqueeBehavior::Looping;
		case 2: return MarqueeBehavior::Bouncing;
		}
	}

	MarqueeDirection MarqueeContainerPage::GetDirectionFromIndex(int value)
	{
		switch (value)
		{
		case 0: return MarqueeDirection::Left;
		case 1: return MarqueeDirection::Right;
		case 2: return MarqueeDirection::Up;
		case 3: return MarqueeDirection::Down;
		}
	}

}
