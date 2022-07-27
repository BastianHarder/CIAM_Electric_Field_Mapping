#ifndef CIAM_ELECTRICALFIELDMAPPING_DATASOURCECONFIG_HPP
#define CIAM_ELECTRICALFIELDMAPPING_DATASOURCECONFIG_HPP
namespace CIAM {
class DataSourceConfig {
public:
  enum class DataSourceType {
    EXTERNAL_RHD2000 = 1,
    FILE_DATA
  };

  explicit DataSourceConfig(DataSourceType sourceType) : dataSourceType(sourceType) {}
  virtual ~DataSourceConfig() = default;

  DataSourceType getDataSourceType() const noexcept {
    return dataSourceType;
  }
private:
  const DataSourceType dataSourceType;
};
}
#endif  // CIAM_ELECTRICALFIELDMAPPING_DATASOURCECONFIG_HPP
