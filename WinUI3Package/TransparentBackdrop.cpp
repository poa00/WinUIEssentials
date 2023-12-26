#include "pch.h"
#include "TransparentBackdrop.h"
#if __has_include("TransparentBackdrop.g.cpp")
#include "TransparentBackdrop.g.cpp"
#endif
#include <winrt/Microsoft.UI.Xaml.Hosting.h>
#include <winrt/Microsoft.UI.Content.h>
#include <dwmapi.h>

namespace winrt::WinUI3Package::implementation
{
    void TransparentBackdrop::OnTargetConnected(winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop connectedTarget, winrt::Microsoft::UI::Xaml::XamlRoot xamlRoot)
    {
        HWND hwnd = (HWND)connectedTarget.as<winrt::Microsoft::UI::Xaml::Hosting::DesktopWindowXamlSource>().SiteBridge().SiteView().EnvironmentView().AppWindowId().Value;
        configureDwm(hwnd);
        if (auto windowEx = WindowEx::GetByHwnd(hwnd))
        {
            windowEx.get()->Transparent(true);
        }
        base_type::OnTargetConnected(connectedTarget, xamlRoot);
    }

    void TransparentBackdrop::OnTargetDisconnected(winrt::Microsoft::UI::Composition::ICompositionSupportsSystemBackdrop connectedTarget)
    {
        connectedTarget.SystemBackdrop(nullptr);
        auto const hwnd = reinterpret_cast<HWND>(connectedTarget.as<winrt::Microsoft::UI::Xaml::Hosting::DesktopWindowXamlSource>().SiteBridge().SiteView().EnvironmentView().AppWindowId().Value);
        if (auto windowEx = WindowEx::GetByHwnd(hwnd))
        {
            windowEx.get()->Transparent(false);
        }
        base_type::OnTargetDisconnected(connectedTarget);
    }

    void TransparentBackdrop::configureDwm(HWND hwnd)
    {
        MARGINS margin{ };
        DWM_BLURBEHIND param;
        param.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
        param.fEnable = true;
        param.hRgnBlur = CreateRectRgn(-2, -2, -1, -1);
        DwmExtendFrameIntoClientArea(hwnd, &margin);
        DwmEnableBlurBehindWindow(hwnd, &param);
    }
}
