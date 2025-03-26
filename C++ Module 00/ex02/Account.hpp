// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account
{
	private:
		static int	_nbAccounts;				//	عدد الحسابات المفتوحة
		static int	_totalAmount;				//	إجمالي الرصيد لجميع الحسابات
		static int	_totalNbDeposits;			//	عدد عمليات الإيداع في كل الحسابات
		static int	_totalNbWithdrawals;		//	عدد عمليات السحب في كل الحسابات
		static void	_displayTimestamp( void );	//	طباعة الطابع الزمني لكل عملية
		int				_accountIndex;			//	رقم الحساب الخاص بالكائن
		int				_amount;				//	الرصيد الحالي للحساب
		int				_nbDeposits;			//	عدد عمليات الإيداع لهذا الحساب
		int				_nbWithdrawals;			//	عدد عمليات السحب لهذا الحساب
		Account( void );						//	منشئ افتراضي بدون معايير

	public:
		Account( int initial_deposit );
		typedef Account		t;
		static int	getNbAccounts( void );
		static int	getTotalAmount( void );
		static int	getNbDeposits( void );
		static int	getNbWithdrawals( void );
		static void	displayAccountsInfos( void );
		void	makeDeposit( int deposit );
		bool	makeWithdrawal( int withdrawal );
		int		checkAmount( void ) const;
		void	displayStatus( void ) const;
		~Account( void );
};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
