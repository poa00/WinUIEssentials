#pragma once

#include "IIncrementLoadingVector.g.h"

namespace winrt::WinUI3Example::implementation
{
    struct IIncrementLoadingVector : IIncrementLoadingVectorT<IIncrementLoadingVector>
    {
        IIncrementLoadingVector() = default;

        auto VectorChanged(winrt::event_token const& token)
        {
            return m_impl.VectorChanged(token);
        }

        auto VectorChanged(winrt::Windows::Foundation::Collections::VectorChangedEventHandler<winrt::Windows::Foundation::IInspectable> const& vhnd)
        {
            return m_impl.VectorChanged(vhnd);
        }

        void ReplaceAll(winrt::array_view<winrt::Windows::Foundation::IInspectable const> const& items)
        {
            m_impl.ReplaceAll(items);
        }

        void RemoveAtEnd()
        {
            m_impl.RemoveAtEnd();
        }

        void RemoveAt(uint32_t index)
        {
            m_impl.RemoveAt(index);
        }

        void InsertAt(uint32_t index, winrt::Windows::Foundation::IInspectable const& value)
        {
            m_impl.InsertAt(index, value);
        }

        bool IndexOf(winrt::Windows::Foundation::IInspectable const& value, uint32_t& index)
        {
            return m_impl.IndexOf(value, index);
        }

        auto GetView()
        {
            return m_impl.GetView();
        }

        auto GetMany(uint32_t startIndex, winrt::array_view<winrt::Windows::Foundation::IInspectable> items)
        {
            return m_impl.GetMany(startIndex, items);
        }

        auto GetAt(uint32_t index)
        {
            return m_impl.GetAt(index);
        }

        auto Clear()
        {
            m_impl.Clear();
        }

        auto Append(winrt::Windows::Foundation::IInspectable const& value)
        {
            m_impl.Append(value);
        }

        void SetAt(uint32_t const& index, winrt::Windows::Foundation::IInspectable const& value)
        {
            m_impl.SetAt(index, value);
        }

        auto Size()
        {
            return m_impl.Size();
        }

        auto First()
        {
            return m_impl.First();
        }
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::Windows::Foundation::IInspectable> m_impl = winrt::single_threaded_observable_vector<winrt::Windows::Foundation::IInspectable>();
    };
}

namespace winrt::WinUI3Example::factory_implementation
{
    struct IIncrementLoadingVector : IIncrementLoadingVectorT<IIncrementLoadingVector, implementation::IIncrementLoadingVector>
    {
    };
}
