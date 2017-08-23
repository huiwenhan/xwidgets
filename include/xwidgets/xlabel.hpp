/***************************************************************************
* Copyright (c) 2017, Sylvain Corlay and Johan Mabille                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#ifndef XWIDGETS_LABEL_HPP
#define XWIDGETS_LABEL_HPP

#include "xmaterialize.hpp"
#include "xstring.hpp"

namespace xeus
{
    /*********************
     * label declaration *
     *********************/

    template <class D>
    class xlabel : public xstring<D>
    {
    public:

        using base_type = xstring<D>;
        using derived_type = D;

        xlabel();
        xjson get_state() const;
        void apply_patch(const xjson& patch);

    private:

        void set_defaults();
    };

    using label = xmaterialize<xlabel>;

    /*************************
     * xlabel implementation *
     ************************/

    template <class D>
    inline xlabel<D>::xlabel()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline xjson xlabel<D>::get_state() const
    {
        xjson state = base_type::get_state();
        return state;
    }

    template <class D>
    inline void xlabel<D>::apply_patch(const xjson& patch)
    {
        base_type::apply_patch(patch);
    }

    template <class D>
    inline void xlabel<D>::set_defaults()
    {
        this->_model_name() = "HTMLModel";
        this->_view_name() = "HTMLView";
    }
}

#endif