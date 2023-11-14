#include "pch.h"
#include "TilesPage.h"
#if __has_include("TilesPage.g.cpp")
#include "TilesPage.g.cpp"
#endif




using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPExample::implementation
{

    void TilesPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        using namespace TilesBuilder;
        using enum TileTemplateNameV3;
        using enum TextStacking;
        using enum Branding;
        

        //Tile()
        //(
        //    Visual()
        //    (
        //        Binding().Template(TileSmall).HintTextStacking(Center)
        //        (
        //            Text().HintAlign(HintAlign::Center)(L"Mon"),
        //            Text().HintAlign(HintAlign::Center).HintStyle(TextStyle::Body)(L"22")
        //        ),
        //        Binding().Template(TileMedium).Branding(Branding::Name).DisplayName(L"Monday 22")
        //    )
        //);
    }
}

void winrt::UWPExample::implementation::TilesPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    //auto t = winrt::Windows::UI::Notifications::TileUpdateManager::GetTemplateContent(winrt::Windows::UI::Notifications::TileTemplateType::TileSquareText03);
    //t.set

//    winrt::Windows::Data::Xml::Dom::XmlDocument doc;
//    doc.LoadXml(LR"(<tile>
//    <visual version="2">
//        <binding template="TileWide310x150ImageAndText01" fallback="TileWideImageAndText01">
//            <image id="1" src=""/>
//            <text id="1">Text1</text>
//        </binding>
//    </visual>
//</tile>)");

    //auto str = t.GetXml();
            m_updater.Clear();
            m_updater.Update(
                Tile()
                (
                    Visual()
                    (
                        Binding().Template(TileTemplateNameV3::TileMedium).Branding(Branding::Name)
                        (
                            Text()(L"Snowboarding Medium")
                            ),
                        Binding().Template(TileTemplateNameV3::TileWide).Branding(Branding::NameAndLogo)
                        (
                            Text()(L"Snowboarding Wide")
                            )
                        )
                    ));

//    winrt::Windows::UI::Xaml::DispatcherTimer timer;
//    timer.Interval(std::chrono::seconds{ 1 });
//    timer.Tick(
//        [this, i = 0](auto...)mutable
//        {
//            winrt::Windows::Data::Xml::Dom::XmlDocument doc;
//            doc.LoadXml(std::format(LR"(<tile>
//  <visual>
//
//    <binding template="TileMedium" branding="logo">
//      <group>
//        <subgroup>
//          <text hint-style="caption">Jennifer Parker</text>
//          <text hint-style="captionSubtle">Photos from our trip</text>
//          <text hint-style="captionSubtle">Check out these awesome photos I took while in New Zealand!</text>
//        </subgroup>
//      </group>
//
//      <text />
//
//      <group>
//        <subgroup>
//          <text hint-style="caption">Steve Bosniak</text>
//          <text hint-style="captionSubtle">Build 2015 Dinner</text>
//          <text hint-style="captionSubtle">Want to go out for dinner after Build tonight?</text>
//        </subgroup>
//      </group>
//    </binding>
//
//    <binding template="TileWide" branding="nameAndLogo">
//        <group>
//            <subgroup>
//              <text hint-style="subtitle">SubTitle Line1 #{}</text>
//              <text hint-style="captionSubtle">caption Line2 #{}</text>
//              <text hint-style="captionSubtle">caption Line3 #{}</text>
//              <text hint-style="captionSubtle">caption Line4 #{}</text>
//              <text hint-style="captionSubtle">caption Line5 #{}</text>
//            </subgroup>
//        </group>
//
//    </binding>
//
//    <binding template="TileLarge" branding="nameAndLogo">
//      <group>
//        <subgroup>
//          <text hint-style="subtitle">Jennifer Parker</text>
//          <text hint-style="captionSubtle">Photos from our trip</text>
//          <text hint-style="captionSubtle">Check out these awesome photos I took while in New Zealand!</text>
//        </subgroup>
//      </group>
//
//      <text />
//
//      <group>
//        <subgroup>
//          <text hint-style="subtitle">Steve Bosniak</text>
//          <text hint-style="captionSubtle">Build 2015 Dinner</text>
//          <text hint-style="captionSubtle">Want to go out for dinner after Build tonight?</text>
//        </subgroup>
//      </group>
//    </binding>
//
//  </visual>
//</tile>
//)", i, i, i, i, i));
//            ++i;
//            winrt::Windows::UI::Notifications::TileNotification notification{ doc };
//            m_updater.Clear();
//            m_updater.Update(notification);
//        }
//    );
//    timer.Start();
}
