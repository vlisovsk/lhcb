#!/bin/bash
sed -i 's;<Value>[0-9][0-9][0-9]</Value>;<Value>0</Value>;' outputXMLFile.xml 
sed -i 's;<ConfigurationParameter>UseAngularAcceptance:True</ConfigurationParameter>;<ConfigurationParameter>UseAngularAcceptance:False</ConfigurationParameter>;' outputXMLFile.xml 
sed -i 's;<OffSetNLL>False</OffSetNLL>;<OffSetNLL>False</OffSetNLL>\n<UseGSLNumericalIntegration>True</UseGSLNumericalIntegration>\n<FixedIntegrationPoints>100000</FixedIntegrationPoints>;' outputXMLFile.xml
