/*
 * This file is part of the sigrok project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBSIGROK_HARDWARE_FX2LAFW_COMMAND_H
#define LIBSIGROK_HARDWARE_FX2LAFW_COMMAND_H

#include "sigrok.h"

/* Protocol commands */
#define CMD_GET_FW_VERSION		0xb0
#define CMD_START			0xb1

#define CMD_START_FLAGS_CLK_SRC_POS	6

#define CMD_START_FLAGS_CLK_30MHZ	(0 << CMD_START_FLAGS_CLK_SRC_POS)
#define CMD_START_FLAGS_CLK_48MHZ	(1 << CMD_START_FLAGS_CLK_SRC_POS)

#pragma pack(push, 1)

struct cmd_start_acquisition {
	uint8_t flags;
	uint8_t sample_delay;
};

#pragma pack(pop)

SR_PRIV int command_start_acquisition(libusb_device_handle *devhdl,
				      uint64_t samplerate);

#endif
