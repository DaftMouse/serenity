/*
 * Copyright (c) 2021, the SerenityOS developers.
 * Copyright (c) 2021, Sam Atkins <atkinssj@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/SettingsWindow.h>
#include <LibGUI/TextEditor.h>
#include <LibGUI/Window.h>

class MailSettingsWidget final : public GUI::SettingsWindow::Tab {
    C_OBJECT_ABSTRACT(MailSettingsWidget)

public:
    static ErrorOr<NonnullRefPtr<MailSettingsWidget>> try_create();

    virtual void apply_settings() override;
    virtual void reset_default_values() override;

private:
    MailSettingsWidget() = default;
    ErrorOr<void> setup();

    DeprecatedString m_server;
    DeprecatedString m_port;
    bool m_tls { false };
    DeprecatedString m_email;
    Vector<DeprecatedString> m_common_ports;

    RefPtr<GUI::TextBox> m_server_inputbox;
    RefPtr<GUI::ComboBox> m_port_combobox;
    RefPtr<GUI::CheckBox> m_tls_checkbox;
    RefPtr<GUI::TextBox> m_email_inputbox;
};
