/* Copyright (c) 2011-2012 William Newbery
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */
//Auto-Generated File
#ifndef GMAPI_FUNCTIONS_COMPUTING_THINGS_DATES_HPP
#define GMAPI_FUNCTIONS_COMPUTING_THINGS_DATES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real date_current_datetime()
    {
        return call(functions[3]);
    }
    
    inline Real date_current_date()
    {
        return call(functions[4]);
    }
    
    inline Real date_current_time()
    {
        return call(functions[5]);
    }
    
    inline Real date_create_datetime(Real year, Real month, Real day, Real hour, Real minute, Real second)
    {
        return call(functions[6], year, month, day, hour, minute, second);
    }
    
    inline Real date_create_date(Real year, Real month, Real day)
    {
        return call(functions[7], year, month, day);
    }
    
    inline Real date_create_time(Real hour, Real minute, Real second)
    {
        return call(functions[8], hour, minute, second);
    }
    
    inline Real date_valid_datetime(Real year, Real month, Real day, Real hour, Real minute, Real second)
    {
        return call(functions[9], year, month, day, hour, minute, second);
    }
    
    inline Real date_valid_date(Real year, Real month, Real day)
    {
        return call(functions[10], year, month, day);
    }
    
    inline Real date_valid_time(Real hour, Real minute, Real second)
    {
        return call(functions[11], hour, minute, second);
    }
    
    inline Real date_inc_year(Real date, Real amount)
    {
        return call(functions[12], date, amount);
    }
    
    inline Real date_inc_month(Real date, Real amount)
    {
        return call(functions[13], date, amount);
    }
    
    inline Real date_inc_week(Real date, Real amount)
    {
        return call(functions[14], date, amount);
    }
    
    inline Real date_inc_day(Real date, Real amount)
    {
        return call(functions[15], date, amount);
    }
    
    inline Real date_inc_hour(Real date, Real amount)
    {
        return call(functions[16], date, amount);
    }
    
    inline Real date_inc_minute(Real date, Real amount)
    {
        return call(functions[17], date, amount);
    }
    
    inline Real date_inc_second(Real date, Real amount)
    {
        return call(functions[18], date, amount);
    }
    
    inline Real date_get_year(Real date)
    {
        return call(functions[19], date);
    }
    
    inline Real date_get_month(Real date)
    {
        return call(functions[20], date);
    }
    
    inline Real date_get_week(Real date)
    {
        return call(functions[21], date);
    }
    
    inline Real date_get_day(Real date)
    {
        return call(functions[22], date);
    }
    
    inline Real date_get_hour(Real date)
    {
        return call(functions[23], date);
    }
    
    inline Real date_get_minute(Real date)
    {
        return call(functions[24], date);
    }
    
    inline Real date_get_second(Real date)
    {
        return call(functions[25], date);
    }
    
    inline Real date_get_weekday(Real date)
    {
        return call(functions[26], date);
    }
    
    inline Real date_get_day_of_year(Real date)
    {
        return call(functions[27], date);
    }
    
    inline Real date_get_hour_of_year(Real date)
    {
        return call(functions[28], date);
    }
    
    inline Real date_get_minute_of_year(Real date)
    {
        return call(functions[29], date);
    }
    
    inline Real date_get_second_of_year(Real date)
    {
        return call(functions[30], date);
    }
    
    inline Real date_year_span(Real date1, Real date2)
    {
        return call(functions[31], date1, date2);
    }
    
    inline Real date_month_span(Real date1, Real date2)
    {
        return call(functions[32], date1, date2);
    }
    
    inline Real date_week_span(Real date1, Real date2)
    {
        return call(functions[33], date1, date2);
    }
    
    inline Real date_day_span(Real date1, Real date2)
    {
        return call(functions[34], date1, date2);
    }
    
    inline Real date_hour_span(Real date1, Real date2)
    {
        return call(functions[35], date1, date2);
    }
    
    inline Real date_minute_span(Real date1, Real date2)
    {
        return call(functions[36], date1, date2);
    }
    
    inline Real date_second_span(Real date1, Real date2)
    {
        return call(functions[37], date1, date2);
    }
    
    inline Real date_compare_datetime(Real date1, Real date2)
    {
        return call(functions[38], date1, date2);
    }
    
    inline Real date_compare_date(Real date1, Real date2)
    {
        return call(functions[39], date1, date2);
    }
    
    inline Real date_compare_time(Real date1, Real date2)
    {
        return call(functions[40], date1, date2);
    }
    
    inline Real date_date_of(Real date)
    {
        return call(functions[41], date);
    }
    
    inline Real date_time_of(Real date)
    {
        return call(functions[42], date);
    }
    
    inline String date_datetime_string(Real date)
    {
        return call(functions[43], date);
    }
    
    inline String date_date_string(Real date)
    {
        return call(functions[44], date);
    }
    
    inline String date_time_string(Real date)
    {
        return call(functions[45], date);
    }
    
    inline Real date_days_in_month(Real date)
    {
        return call(functions[46], date);
    }
    
    inline Real date_days_in_year(Real date)
    {
        return call(functions[47], date);
    }
    
    inline Real date_leap_year(Real date)
    {
        return call(functions[48], date);
    }
    
    inline Real date_is_today(Real date)
    {
        return call(functions[49], date);
    }
    
    ///@}
}
#endif
